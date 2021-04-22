# Engineering-Assistant
工科 辅助软件（长度换算，凯撒、DES与RSA加密，定时录屏，电脑截屏，倒计时，51定时器赋值，清除文本换行等功能）<br>

![BJK_logo icon](https://github.com/bjk12/LittleBird_TypeExercise/blob/main/bjk1.ico)  
## 目录
* [概述](#概述)
  * [软件简介](#软件简介)
  * [版权说明](#版权说明)
* [使用说明](#使用说明)
  * [第一界面](#第一界面)
  * [第二界面](#第二界面)

## 概述
### 软件简介
&#8195;&#8195;本软件的全称为“**工科辅助设计软件**”，意思是希望通过本软件能为广大大专院校的工科生们提供一个辅助他们完成工程设计的工具，
减少重复或不必要的工作量，鼓励他们利用本软件进行发明与创新。<br>

&#8195;&#8195;工科辅助设计软件采用面向对象的设计方法，利用 **C++编程语言** 和 **Qt Creator 4.5.1开发平台** 开发平台进行设计编写。
本软件主要针对广大工科生们在进行工程设计或科研创新时需要完成许多重复性工作和使用各类辅助性工具来回切换的问题，不仅通过人机交互界面帮助用户完成了重复性的工作，
还集成了一些能够优化用户使用体验的高级功能，如**取消换行**、**定时录屏**和**文本信息加密解密**等。 <br>

&#8195;&#8195;在安装并打开本软件后，用户可以通过本软件对长度单位进行英制与公制之间的换算，计算STC89C51单片机在定时方式1或者定时方式2下8位寄存器TH0(或TH1)和TL0（或TL1）的应赋数值，
在调试硬件时设置倒计时并可以随时暂停，同时本软件还具有将信息（仅限数字和字母）按多种方式进行加解密，全屏截图，定时录屏以及删除所给文本的所有换行符等高级功能。<br>

**No picture,No truth:**<br>

界面截图：<br>
<div align=center><img src="https://github.com/bjk12/Engineering-Assistant/blob/main/pic4_readme/image019.png" alt="pic4_readme"/></div><br>

<div align=center><img src="https://github.com/bjk12/Engineering-Assistant/blob/main/pic4_readme/image038.png" alt="pic4_readme"/></div><br>

### 版权说明
已申软著，请勿商用 (＃｀д´)ﾉ<br>
## 使用说明
&#8195;&#8195;工科辅助设计软件主要包括两个界面：第一界面和第二界面。<br>

&#8195;&#8195;第一界面主要包括**长度换算功能、全屏截图功能、定时录屏功能和数据加解密功能**；<br>
&#8195;&#8195;第二界面主要包括**倒计时功能、51单片机定时器赋值功能和取消换行功能**。<br>

&#8195;&#8195;点击第一界面右下角的“下一页”按钮就可以跳转到第二界面，点击第二界面右上角的“上一页”按钮就可以跳转回第一界面。
需要注意的是，想正常退出本软件只能通过点击第一界面右上角的叉号退出，当用户使用第二界面时无法正常退出程序，
需要点击第二界面右上角的“上一页”按钮跳转回第一界面后点击第一界面右上角的叉号才能正常退出本软件。<br>

### 第一界面
<div align=center><img src="https://github.com/bjk12/Engineering-Assistant/blob/main/pic4_readme/image019.png" alt="pic4_readme"/></div>
<p align="center">图1</p>
&#8195;&#8195;如图1所示，用户通过双击桌面快捷方式开启第一界面。第一界面包括“换算”按钮、“开始”按钮、“中断”按钮、“截屏”按钮、“加密”按钮、“解密”按钮、“下一页”按钮、加密方式选择框、英制长度文本框、公制长度文本框、加解密文本框、加密结果文本框、解密结果文本框、起始小时文本框、起始分钟文本框、结束小时文本框和结束分钟文本框等功能组件。接下来本文将按照正常的使用顺序对以上组件的功能进行介绍。<br>

<div align=center><img src="https://github.com/bjk12/Engineering-Assistant/blob/main/pic4_readme/image020.png" alt="pic4_readme"/></div>
<p align="center">图2</p>
<div align=center><img src="https://github.com/bjk12/Engineering-Assistant/blob/main/pic4_readme/image021.png" alt="pic4_readme"/></div>
<p align="center">图3</p>
&#8195;&#8195;如图2所示，用户首先在英制长度文本框（或公制长度文本框）中输入需要换算的长度， 然后点击“换算”按钮完成换算，如图3所示，对应的公制（或英制）长度文本框中就会显示出长度换算的结果。用户可以将文本框中的计算结果直接复制粘贴到其他文本中进行使用。<br>

<div align=center><img src="https://github.com/bjk12/Engineering-Assistant/blob/main/pic4_readme/image022.png" alt="pic4_readme"/></div>
<p align="center">图4</p>
&#8195;&#8195;如图4所示，长度换算模块提供输入检查功能，即当用户在未输入数据就点击“换算”按钮时程序会弹出名为“温馨提示”的消息框，提醒用户“请先在英制文本框或公制文本框中输入数字，再点击此按钮完成换算”。<br>

<div align=center><img src="https://github.com/bjk12/Engineering-Assistant/blob/main/pic4_readme/image023.png" alt="pic4_readme"/></div>
<p align="center">图5</p>
&#8195;&#8195;如图5所示，长度换算模块提供输入检查功能，当用户向文本框中输入非法字符时程序会弹出名为“温馨提示”的消息框，提醒用户“请输入有意义的数字”。<br>
<div align=center><img src="https://github.com/bjk12/Engineering-Assistant/blob/main/pic4_readme/image024.png" alt="pic4_readme"/></div>
<p align="center">图6</p>
&#8195;&#8195;如图6所示，当使用凯撒加密方式时，用户首先在加解密文本框中输入待加密的文本信息（仅限字母和数字），然后在加密方式选择框中选择“凯撒加密”，之后点击右侧的“加密”按钮，加密文本框中就会出现对应的密文。<br>

<div align=center><img src="https://github.com/bjk12/Engineering-Assistant/blob/main/pic4_readme/image025.png" alt="pic4_readme"/></div>
<p align="center">图7</p>
&#8195;&#8195;如图7所示，用户首先在加解密文本框中输入待解密的文本信息（仅限字母和数字），然后在加密方式选择框中选择“凯撒加密”，之后点击右侧的“解密”按钮，解密文本框中就会出现解密后的明文。<br>

<div align=center><img src="https://github.com/bjk12/Engineering-Assistant/blob/main/pic4_readme/image026.png" alt="pic4_readme"/></div>
<p align="center">图8</p>
&#8195;&#8195;如图8所示，当使用DES加密方式时，用户首先在加解密文本框中输入待加密的文本信息，然后在加密方式选择框中选择“DES加密”，之后点击 “加密”按钮，加密文本框中就会出现对应的密文。<br>

<div align=center><img src="https://github.com/bjk12/Engineering-Assistant/blob/main/pic4_readme/image027.png" alt="pic4_readme"/></div>
<p align="center">图9</p>
&#8195;&#8195;如图9所示，用户首先在加解密文本框中输入待解密的文本信息，然后在加密方式选择框中选择“DES加密”，之后点击“解密”按钮，解密文本框就会显示解密后的明文。<br>

<div align=center><img src="https://github.com/bjk12/Engineering-Assistant/blob/main/pic4_readme/image028.png" alt="pic4_readme"/></div>
<p align="center">图10</p>
&#8195;&#8195;如图10所示，当使用RAS加密方式时，用户首先在加解密文本框中输入待加密的文本信息，然后在加密方式选择框中选择“RSA加密”，之后点击 “加密”按钮，加密文本框中就会出现对应的密文。<br>

<div align=center><img src="https://github.com/bjk12/Engineering-Assistant/blob/main/pic4_readme/image029.png" alt="pic4_readme"/></div>
<p align="center">图11</p>
&#8195;&#8195;如图11所示，用户首先在加解密文本框中输入待解密的文本信息，然后在加密方式选择框中选择“RSA加密”，之后点击“解密”按钮，解密文本框就会显示解密后的明文。<br>

<div align=center><img src="https://github.com/bjk12/Engineering-Assistant/blob/main/pic4_readme/image030.png" alt="pic4_readme"/></div>
<p align="center">图12</p>
&#8195;&#8195;如图12所示，当使用定时录屏功能时，用户需要先设置录屏的开始时刻和结束时刻，然后点击“开始”按钮。程序会在开始时刻自启动录屏功能，在结束时刻自动停止录屏功能。在软件定时录屏期间，用户随时可以通过点击“中断”按钮主动停止录屏功能。录屏数据被命名为“QM +当前时间.avi”并保存于安装目录下，录屏效果如图13所示。<br>

<div align=center><img src="https://github.com/bjk12/Engineering-Assistant/blob/main/pic4_readme/image031.png" alt="pic4_readme"/></div>
<p align="center">图13</p>
<div align=center><img src="https://github.com/bjk12/Engineering-Assistant/blob/main/pic4_readme/image032.png" alt="pic4_readme"/></div>
<p align="center">图14</p>
&#8195;&#8195;如图14所示，数据加密模块提供输入检查功能，即当用户在未输入数据就点击“换算”按钮时，加解密文本框会显示提示信息，提醒用户“请输入数据。”<br>

<div align=center><img src="https://github.com/bjk12/Engineering-Assistant/blob/main/pic4_readme/image033.png" alt="pic4_readme"/></div>
<p align="center">图15</p>
&#8195;&#8195;如图15所示，数据加密模块提供输入检查功能，当用户向文本框中输入非法字符时，加解密文本框会显示提示信息，提醒用户“抱歉，目前无法加密汉字，请输入英文字母或数字。”<br>

<div align=center><img src="https://github.com/bjk12/Engineering-Assistant/blob/main/pic4_readme/image034.png" alt="pic4_readme"/></div>
<p align="center">图16</p>
&#8195;&#8195;如图16所示，当使用全屏截图功能时，用户只需点击“截屏”按钮，程序就会全屏截图，并以“QM+数字.jpg”命名，然后保存到安装目录下的“temp”文件夹中供用户查看和使用，如图17所示。<br>

<div align=center><img src="https://github.com/bjk12/Engineering-Assistant/blob/main/pic4_readme/image035.png" alt="pic4_readme"/></div>
<p align="center">图17</p>
<div align=center><img src="https://github.com/bjk12/Engineering-Assistant/blob/main/pic4_readme/image036.png" alt="pic4_readme"/></div>
<p align="center">图18</p>
&#8195;&#8195;全屏截图功能所保存的图片效果如图18所示。<br>

<div align=center><img src="https://github.com/bjk12/Engineering-Assistant/blob/main/pic4_readme/image037.png" alt="pic4_readme"/></div>
<p align="center">图19</p>
&#8195;&#8195;如图19所示，用户可以通过点击“下一页”按钮跳转至第二界面。<br>

### 第二界面
<div align=center><img src="https://github.com/bjk12/Engineering-Assistant/blob/main/pic4_readme/image038.png" alt="pic4_readme"/></div>
<p align="center">图20  第二界面</p>
<div align=center><img src="https://github.com/bjk12/Engineering-Assistant/blob/main/pic4_readme/image039.png" alt="pic4_readme"/></div>
<p align="center">图21</p>
<div align=center><img src="https://github.com/bjk12/Engineering-Assistant/blob/main/pic4_readme/image040.png" alt="pic4_readme"/></div>
<p align="center">图22</p>
&#8195;&#8195;如图21所示，当使用倒计时功能时，用户首先设置倒计时时间，然后点击“开始”按钮，程序开始倒计时。用户随时可以通过点击“暂停”按钮停止倒计时功能。设置时间文本框中会实时刷新剩余时间，已用时间文本框会实时刷新已经流逝的时间，倒计时效果如图22所示。<br>

<div align=center><img src="https://github.com/bjk12/Engineering-Assistant/blob/main/pic4_readme/image041.png" alt="pic4_readme"/></div>
<p align="center">图23</p>
<div align=center><img src="https://github.com/bjk12/Engineering-Assistant/blob/main/pic4_readme/image042.png" alt="pic4_readme"/></div>
<p align="center">图24</p>
&#8195;&#8195;如图23所示，当使用寄存器赋值功能时，首先输入定时时间（单位微秒），然后在定时方式选择框中选择需要的定时方式（目前仅支持方式1和方式2），最后点击“计算”按钮。如图24所示，高八位文本框和低八位文本框会显示计算结果，用户可以将文本框中的计算结果直接复制粘贴到其他文本中进行使用。<br>

<div align=center><img src="https://github.com/bjk12/Engineering-Assistant/blob/main/pic4_readme/image043.png" alt="pic4_readme"/></div>
<p align="center">图25</p>
&#8195;&#8195;如图25所示，当使用取消换行功能时，首先在“需要修改的文本：”下面的文本框中输入或粘贴为纯文本，然后点击“取消换行”按钮，“修改后：”下面的文本框中就会显示处理后的文本信息。用户可以将文本框中的信息直接复制粘贴到其他文本中进行使用。<br>

<div align=center><img src="https://github.com/bjk12/Engineering-Assistant/blob/main/pic4_readme/image044.png" alt="pic4_readme"/></div>
<p align="center">图26</p>
&#8195;&#8195;如图26所示，取消换行模块提供输入检查功能，即当用户在未输入数据就点击“取消换行”按钮时，加解密文本框会显示提示信息，提醒用户“请输入数据。”<br>

<div align=center><img src="https://github.com/bjk12/Engineering-Assistant/blob/main/pic4_readme/image045.png" alt="pic4_readme"/></div>
<p align="center">图27</p>
&#8195;&#8195;如图27所示，用户可以通过点击“上一页”按钮跳转回第一界面。 <br>
&#8195;&#8195;<br>
