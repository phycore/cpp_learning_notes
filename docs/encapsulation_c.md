#### C 語言如何做封裝

1. C 語言為程序導向語言(Procedure-Oriented Programming)，非物件導向(Object-Oriented Programming)。
    - 不論是程序導向或是物件導向，並非語法限制，而是對軟體設計思維方式的差異。
    - 程序導向如同工廠的流水線作業，物件導向則是模組間物件與物件的互動。
    - 物件導向的 C++ 也可以寫成程序導向做法，程序導向的 C 也可以寫成物件導向的做法。

1. C 語言不支援 class 語法，但可以利用 struct 模仿 class 的封裝。
    - 同樣是[計數器](../src/counter/counter.hpp)的例子，利用 C 語言 struct 模仿 C++ 類別(class)。
    - **私有成員屬性**，藉由不透明指標(opaque pointer)達成。
    - **公開成員方法**，藉由函數指標(function pointer)達成。
    - [counter.h](../src/counter/counter.h)
    ```c
    typedef struct counter_obj {
    // private:
        /* 不透明指標 */
        void* data;
    // public:
        /* 函數指標 */
        void (*reset)(struct counter_obj* p_self);
        void (*accumulate)(struct counter_obj* p_self);
        void (*depreciate)(struct counter_obj* p_self);
        int32_t (*get_counts)(struct counter_obj* p_self);
    } counter_obj_t;
    ```
    - **私有成員方法**，藉由靜態函式(static function)達成，並宣告與定義在 source *.c 檔案。
    - [counter_impl.c](../src/counter/counter_impl.c#L19)
    ```c
    /* 靜態函式 */
    static void write_counts(counter_obj_t* p_this, int32_t write_value);
    static int32_t read_counts(counter_obj_t* p_this);
    ```
    - **this 指標**，藉由自身 struct 指標 `counter_obj_t* p_this` 或 `struct counter_obj* p_self` 為引數代入。

1. 套用轉接器模式(adapter pattern)，讓 struct 模仿 class。
    - [c2cpp_adapter.h](../include/c2cpp_adapter.h)
    ```c
    // Imitate private members. (by opaque pointer)
    typedef void* private_t;

    // Imitate C++ private methods. (static function in src *.c)
    #define private static

    // Imiteate C++ public members. (Itsn't working in C.)
    #define public_t

    // Imitate C++ public methods. (Itsn't working in C.)
    #define public

    // Macro function to imitate C++ new and delete operator.
    #define NEW_OBJECT(obj_name) struct obj_name* new_##obj_name(void)

    #define DELETE_OBJECT(obj_name) void delete_##obj_name(struct obj_name* p_obj)
    ```
    - 可以得到如[counter.h](../src/counter/counter.h)的外觀。
    - **new 和 delete 運算子**，藉由 macro function 模仿，做其宣告，定義則在所屬的 source *.c 檔案。
    - [counter_impl.c](../src/counter/counter_impl.c#L91)
    ```c
    struct counter_obj* new_counter_obj(void) {
        /* 略 */
        struct counter_obj* p_counter = (struct counter_obj*)plat_allocate(alloc_size);
        return p_counter;
        /* 略 */
    }

    void delete_counter_obj(struct counter_obj* p_obj) {
        /* 略 */
        PLAT_FREE(p_obj);
        /* 略 */
    }
    ```

1. [counter 單元測試](../tests/test_counter.cpp#L119)。
    - 重置測試
    - 遞增測試
    - 遞減測試
    - 先增後減
    - 先減後增

1. 後記
    - 個人 C 語言的實務開發經驗，不建議再用個 [addapter](../include/c2cpp_adapter.h) 去做臨摹。
        - 轉接層內容越多的結果，C 語言如同被不必要的紗布覆蓋，降低閱讀與維護性。
        - 多一層甚至多層的 macro 巨集顯得過度設計。
        - 經驗上，如果連 IDE 偵測都無法順利展開 macro 那就是失敗的設計。
    - 採用原生 C 的語法，直觀的閱讀更便於維護。
    - 如果無法歸納出抽象類別，也無須硬做，多一層衍生類別(繼承)，並不會讓模組化的 C 語言看起來更優雅。

1. 參考資料
    1. 李運華 (2021)。《編寫程式的邏輯: 如何用物件導向實做複雜的業務需求》。 ch01: 物件導向概述。台北市: 碩博文化。
    1. Richard Reese(2013)。 《透視C語言指標》。 ch8: 其他補充。莊弘祥譯。台北市: 碁峯資訊。
    1. Ben Klemens(2015)。 《21世紀C語言》第二版。 ch11: C 語言的物件導向程式設計。莊弘祥譯。台北市: 碁峯資訊。
    1. Kamran Amini(2019): *Extreme C*, ch6: OOP and Encapsulation, UK., Packt