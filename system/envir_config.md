---
date: 2020-10-16 14:00:00
---


## JDK

[Ori] : http://www.oracle.com/technetwork/java/javase/downloads/index.html

```bash
# Win10 bin/jlink.exe --module-path jmods --add-modules java.desktop --output jre
bin/jlink --module-path jmods --add-modules java.desktop --output jre

sudo mv jdkXXX /usr/lib/XXX
sudo vim ~/.bashrc #Bash && ZSH 不一样

export JAVA_HOME=/usr/libl/jdkXXX  
export JRE_HOME=${JAVA_HOME}/jre  
export CLASSPATH=.:${JAVA_HOME}/lib:${JRE_HOME}/lib  
export PATH=${JAVA_HOME}/bin:$PATH

sudo source ~/.bashrc && java --version

```

## SDK

[Ori] : https://developer.android.com/studio#downloads

我记得自己是挂了代理进去设置的, 一直在Download T_T

**参考**: 
- https://developer.android.com/studio/intro/update#sdk-manager 
- https://developer.android.com/studio#cmdline-tools
- https://stackoverflow.com/questions/34556884/how-to-install-android-sdk-on-ubuntu
- https://www.jianshu.com/p/8a2fad182168
- https://blog.csdn.net/x199699/article/details/82354051



## CPP

**[LINK]** https://code.visualstudio.com/docs/cpp/config-linux


[Need] : gcc , g++ , (c)make

Diff between cmake and make 
[Ori] https://stackoverflow.com/questions/25789644/difference-between-using-makefile-and-cmake-to-compile-the-code/25790020#25790020
> Make (or rather a Makefile) is a buildsystem - it drives the compiler and other build tools to build your code.
> CMake is a generator of buildsystems. It can produce Makefiles, it can produce Ninja build files, it can produce KDEvelop or Xcode projects, it can produce Visual Studio solutions. From the same starting point, the same CMakeLists.txt file. So if you have a platform-independent project, CMake **is****** a way to make it buildsystem-independent as well.
> If you have Windows developers used to Visual Studio and Unix developers who swear by GNU Make, CMake is (one of) the way(s) to go.
> I would always recommend using CMake (or another buildsystem generator, but CMake is my personal preference) if you intend your project to be multi-platform or widely usable. CMake itself also provides some nice features like dependency detection, library interface management, or integration with CTest, CDash and CPack.
> Using a buildsystem generator makes your project more future-proof. Even if you're GNU-Make-only now, what if you later decide to expand to other platforms (be it Windows or something embedded), or just want to use an IDE?
