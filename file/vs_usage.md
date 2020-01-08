# visual stadio usage

## hot key
```
CTRL K -> CTRL F    // 自动对齐
CTRL J              // 智能提示
ALT Right           // 智能提示
CTRL M -> CTRL M    // 快速显示/隐藏当段代码
CTRL -              // 回到上次光标的位置
CTRL SHIFT -        // 前进到下一个光标位置
CTRL K -> CTRL C    // 注释选择语句
CTRL K -> CTRL U    // 取消注释
CTRL Z              // 撤销操作
CTRL Y              // 回滚撤销
```

## count code lines
```
SHIFT CTRL F
输入" ^:b*[^:b#/]+.*$ "  // 无引号，无空格，#开头和/开头或者空行都不计入代码量
查找勾上支持正则表达式
查看最后一行输出
```

## project setting (recommending)
```
Configuration Properties
	General
		Output Directory = ../bin
		Intermediate Directory = ../object
	C/C++
		General
    		#set the 3rdpart included file directory
			Additional Include Directories = ../include
		Precompiled Head
			Precompiled Header = Not Using Precompiled Headers
	Linker
		General
		    #set the root directory of ***.lib
			Additional Library Directories = ../lib/***
		Input
			Additional Dependencies = ***.lib
```


