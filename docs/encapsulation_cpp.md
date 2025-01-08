#### 封裝(Encapsulation)

1. C++ 的封裝是藉由類別(class)達成，使用封裝的主要兩個原因:
    1. **保護隱私**。
    1. **隱藏實做，隔離複雜度**。

1. 需求: 一個有遞增和遞減功能的計數器。

1. 設計一個**計數器類別**
    - **屬性(attribute)**
        - 計數值(counts_number)。
    - **方法(methods)**
        - 重置(reset)。
        - 遞增(accumulate)。
        - 遞減(depreciate)。
        - 取得計數值(getCounts)。

1. [counter.hpp](../src/counter/counter.hpp#top)
    ```c++
    class counter {
       private:
        int32_t counts_number;
        void write_counts(int32_t write_value);
        int32_t read_counts(void);

       public:
        void reset(void);
        void accumulate(void);
        void depreciate(void);
        int32_t getCounts(void);
    };
    ```

1. 說明
    - 保護隱私成員 `counts_number`，不被呼叫 counter 的模組直接存取儲存值。
    - 隱藏了計數器遞增與遞減的實做，因為呼叫 counter 的模組不需要知道計數器怎麼實做；只有透過開放的介面告訴 counter 遞增與遞減的時機。

1. 語法
    - C++ 中以**存取指定符(access specifiers)** 進行強制封裝。

    - `public:` 指定符，定義了類別的介面。
        呼叫 counter 的模組，透過介面告訴計數器遞增、遞減的時機點，也可以取得當前計數值。

    - `private:` 指定符，封裝隱藏了實做。
        呼叫該類別的模組無法存取。

1. [counter.cpp](../src/counter/counter.cpp#top)
    ```c++
    void counter::write_counts(int32_t write_value) { this->counts_number = write_value; }

    int32_t counter::read_counts(void) { return this->counts_number; }

    void counter::reset(void) { write_counts(0); }

    void counter::accumulate(void) { this->counts_number++; }

    void counter::depreciate(void) { this->counts_number--; }

    int32_t counter::getCounts(void) { return read_counts(); }
    ```

1. 語法
    - 範疇運算子(scope operator)
        - Microsoft Learn-[Scope resolution operator: `::`](https://learn.microsoft.com/en-us/cpp/cpp/scope-resolution-operator?view=msvc-170)
    - this 指標(this pointer)
        - Microsoft Learn-[The `this` pointer](https://learn.microsoft.com/en-us/cpp/cpp/this-pointer?view=msvc-170)
        - 類別成員函式的隱含參數。
        - 呼叫類別成員函式，在上物件的位址。
        - 範例說明:
        ```c++
        counter counter_A;
        counter_A.reset();
        counter_A.accumulate();
        /* 等同編譯器呼叫 */
        /* counter_A.accumulate(&counter_A);*/
        /* 成員函式 accumulate 可以使用隱含參數 this 指標，指向物件 counter_A 的位址*/
        ```
        - C 語言模仿 C++ this 指標: 將自身結構的記憶體位址 `struct counter_obj* p_self` 為引數代入函式。
        ```c
        typedef struct counter_obj {
            void (*accumulate)(struct counter_obj* p_self);
        } counter_obj_t;
        ```

1. [counter 單元測試](../tests/test_counter.cpp#top)。
    - 重置測試
    - 遞增測試
    - 遞減測試
    - 先增後減
    - 先減後增

1. [C 語言如何做封裝](/docs/encapsulation_c.md)。

1. 後記: 優先專注程式碼運行與要點整理。
    - 待補充物件導向的專有名詞。
        - 封裝前的抽象化(abstraction)。
        - 介面(interface)。
        - 實做(implementation)。
        - 物件(object)與類別的差異。
        - 實例(instance)。

1. 參考資料
    1. 李運華 (2021)。《編寫程式的邏輯: 如何用物件導向實做複雜的業務需求》台北市: 碩博文化。
    1. Stanley B. Lippman(2012)。《C++ Primer 中文版》5th edition。黃銘偉譯。台北市: 碁峯資訊。
    1. Stanley B. Lippman(2012): *C++ Primer 5th edition* U.S., Addition-Wisely
    1. [Microsoft Learn Challenge: Microsoft C++, C, and Assembler documentation](https://learn.microsoft.com/en-us/cpp/?view=msvc-170)