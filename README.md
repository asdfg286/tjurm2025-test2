# OpenCV作业

#### 一、安装步骤

1. 按照上次作业的下载流程下载本次作业即可
2. 使用vscode**打开该代码文件夹**，如下：
   ![alt text](image/README/1730728085502.png)
3. 右键点击左侧文件列表的空白位置，新建文件夹：`.vscode`，注意前面有个 `.`，在里面添加一个文件 `c_cpp_properties.json`，用于设置代码补全的搜索路径，内容如下：

   ```json
   {
       "configurations": [
           {
               "name": "Linux",
               "includePath": [
                   "${workspaceFolder}/**",
                   "/usr/local/opencv4.5.4/include/opencv4"    //就是你安装opencv的目录
               ],
               "defines": [],
               "compilerPath": "/usr/bin/gcc",
               "cStandard": "c11",
               "cppStandard": "gnu++14",
               "intelliSenseMode": "linux-gcc-x64"
           }
       ],
       "version": 4
   }
   ```

![alt text](image/README/1730728256839.png)

4. 点开main.cc，如果没出现任何错误提示（红色下划线），就说明一切正常。

#### 二、作业简介

在这个作业中我们设置了多个练习来帮助大家熟悉OpenCV的常用操作（针对自瞄），每个练习都需要使用OpenCV来实现一些功能函数，截止目前总共有9个练习，在 `include/impls.h`中能够看到，每个函数对应了一个练习。

```c++
// 练习 (1)
std::vector<cv::Mat> split(const cv::Mat& rgb_image);

// 练习 (2)
std::vector<cv::Mat> threshold(const cv::Mat& src, int threshold_value);
...
```

**针对某一个练习，大家需要做的就是在代码文件：`src/函数名/impl.cc`中按照注释内的指导实现这个函数。**

#### 三、运行方式

每个练习对应了一个名字，所有的练习如下所示：

```
erode
find_contours
rect
split
threshold
compute_iou
compute_area_ratio
roi_color
resize
```

实际上可以看 `main.cc`里的 `16~33`行就知道每个测试点的名字跟函数的对应关系了。

1. `opencv`文件夹的根目录下有一个 `run.list`文件，里面内容如下：

   ```

   stop

   erode
   find_contours
   rect
   split
   threshold
   compute_iou
   compute_area_ratio
   roi_color
   resize
   ```
   假设你要运行 `erode`，`find_contours`两个测试点，你就把这两行挪到 `stop`上面就行，`stop`以下的都不会被运行。
2. 设置好 `run.list`之后，使用下面的命令编译测试程序：

   ```shell
   mkdir build
   cd build
   cmake ..
   make -j4
   ```
   注意，一行一行执行，别直接图省事儿一次性复制了。
   你会看到：
   `<img src="image/README/2022-10-23 15-27-02 的屏幕截图.png" style="zoom: 33%;" />`
3. 编译完之后，在 `build`目录下执行：

   ```shell
   ./tjurm_tutorial
   ```
   运行所有的测试点，每个测试点会有输出内容，认真看就行了。
4. 每次修改代码后，都要在 `build`目录下执行：

   ```shell
   cmake ..
   make -j4
   ./tjurm_tutorial
   ```
   否则代码修改无效。
