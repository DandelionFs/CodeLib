---
date: 2020-10-19 16:20:00
---

**五种布局： FrameLayout 、 LinearLayout 、 AbsoluteLayout 、 RelativeLayout 、 TableLayout 全都继承自ViewGroup，各自特点及绘制效率对比。**
* FrameLayout(框架布局)
    此布局是五种布局中最简单的布局，Android中并没有对child view的摆布进行控制，这个布局中所有的控件都会默认出现在视图的左上角，我们可以使用``android:layout_margin``，``android:layout_gravity``等属性去控制子控件相对布局的位置。
* LinearLayout(线性布局)
    一行（或一列）只控制一个控件的线性布局，所以当有很多控件需要在一个界面中列出时，可以用LinearLayout布局。
        此布局有一个需要格外注意的属性:``android:orientation=“horizontal|vertical``。
    * 当`android:orientation="horizontal`时，*说明你希望将水平方向的布局交给**LinearLayout** *，其子元素的`android:layout_gravity="right|left"` 等控制水平方向的gravity值都是被忽略的，*此时**LinearLayout**中的子元素都是默认的按照水平从左向右来排*，我们可以用`android:layout_gravity="top|bottom"`等gravity值来控制垂直展示。
    *     * 反之，可以知道 当`android:orientation="vertical`时，**LinearLayout**对其子元素展示上的的处理方式。
* AbsoluteLayout(绝对布局)
    可以放置多个控件，并且可以自己定义控件的x,y位置
* RelativeLayout(相对布局)
    这个布局也是相对自由的布局，Android 对该布局的child view的 水平layout& 垂直layout做了解析，由此我们可以FrameLayout的基础上使用标签或者Java代码对垂直方向 以及 水平方向 布局中的views进行任意的控制.
    * 相关属性：
    ```
    android:layout_centerInParent="true|false"
	android:layout_centerHorizontal="true|false"
	android:layout_alignParentRight="true|false"
	```
* TableLayout(表格布局)
    将子元素的位置分配到行或列中，一个TableLayout由许多的TableRow组成
        