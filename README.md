## C++ 學習筆記

### 主題
#### 物件導向程式設計(Object-Oriented Programming)
- ##### [封裝(Encapsulation)](docs/encapsulation_cpp.md#top)
- ##### 繼承(Inheritance)
- ##### 多型 (Polymorphism)

#### 設計模式(Design Patterns)
- ##### 轉接器模式(Adapter Pattern)
- ##### 命令模式(Command Pattern)

#### 先問自己為何要學 C++?
1. 非本科從事數年寫程式碼工作，除了遇過一些有趣的數學與演算法問題，**高規格眼光看待**，大部分還是從事低階碼農的工作。

1. 主要開發為 C 語言([MCU](https://www.arm.com/products/silicon-ip-cpu/cortex-m/cortex-m4), [TrustZone](https://www.arm.com/technologies/trustzone-for-cortex-a), [Android Native](https://developer.android.com/ndk))，因有機會打造工具需求發現 [C++ STL container](https://cplusplus.com/reference/stl/) 的好用之處，不同於 C 在硬體資源取捨，要「刻」自己的資料結構。

1. 經歷過不同公司且兩次產品軟體重構，都在討論模組化與物件導向，卻還是用 C 「刻」物件導向，一是閱讀門檻高，二是少了練習原生 [OOP](https://www.techtarget.com/searchapparchitecture/definition/object-oriented-programming-OOP) 語法的遺憾，那為何不直接用 C++? 考量交付客戶版本兼容性、付費 compiler 支援性還有可安全執行環境使用 C 的代價比 C++ 小很多。

1. 用 C 語言模組化開發，實做封裝、繼承與多型，以我任職過的實務經驗來說，大幅降低了 C 語言的閱讀性與直覺性，相當於提高要求工程師對 C 語言掌握能力，還要加上對 OOP 的認識。

1. C 語言沒有像 [C++ smart pointer](https://learn.microsoft.com/en-us/cpp/cpp/smart-pointers-modern-cpp?view=msvc-170) 自動回收記憶體的支援([garbage collector](https://en.wikipedia.org/wiki/Garbage_collection_(computer_science)))，動態記憶體管理必須由開發工程師負責。

1. 自己用 C 刷 [LeetCode](https://leetcode.com/) 刷到懷疑人蔘。

1. 看到 GitHub 上千 star 的 repo. 人家的程式碼怎麼寫、專案怎麼佈署、Unit Tests 怎麼做...等等，對照自己的開發經驗，令人回味與起勁!

1. 當了幾年的碼農，深刻的體悟，不外乎**常看原始碼(效仿)**和**動手做(練習)**，其實就是邊做邊學，多做才有感覺，回到最原始的回饋就是**把自己的想法以程式碼落實並正確作動就會興奮**。

1. 其實找個 C++ 開源專案或**挑個題目做**，是**學習成效最高**的，這邊主要是**紀錄筆記**。

1. 軟體工程師不要怕被 AI 取代，因為它還沒取代我之前，我就被其他人取代了，共勉之。