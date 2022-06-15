# Rengin

本项目实现了games202的所有作业，一下是各种效果

SSR

![image-20220601140032473](https://github.com/Conqcd/Rengin/blob/main/images/image-20220601140032473.png)

![image-20220601141119019](https://github.com/Conqcd/Rengin/blob/main/images/image-20220601141119019.png)

屏幕空间的光线追踪，用以达成镜面反射的效果。

shadowmap：

![image-20220601142025843](https://github.com/Conqcd/Rengin/blob/main/images/image-20220601142025843.png)

采用PCSS方法,可以看到离人越远，阴影越淡和越软，离人越近则相反。

PRT

![image-20220601142111435](https://github.com/Conqcd/Rengin/blob/main/images/image-20220601142111435.png)

![image-20220601142119924](https://github.com/Conqcd/Rengin/blob/main/images/image-20220601142119924.png)

![image-20220601142126264](https://github.com/Conqcd/Rengin/blob/main/images/image-20220601142126264.png)

基于预计算辐射率传播函数的动态低频环境光场景的实时渲染，先给整个场景做个烘培，然后得到球谐函数的参数，传进去以达到实时渲染的效果，上图分别为没有光线追踪效果和有的效果。

PBR

![image-20220602193511298](https://github.com/Conqcd/Rengin/blob/main/images/image-20220602193511298.png)

![image-20220602193538586](https://github.com/Conqcd/Rengin/blob/main/images/image-20220602193538586.png)

基于物理的材质。这是基于微平面理论模型，其中一部分光线在内部被遮挡，没有反弹出来，造成能量损失。通过预计算得到相应的能量损失，再diffuse物体上尤为明显，从最右边的看第一幅图是做了能量补偿的，明显要更明亮一些。

实时光线追踪：

![image-20220613194245636](https://github.com/Conqcd/Rengin/blob/main/images/image-20220613194245636.png)

![image-20220613194302486](https://github.com/Conqcd/Rengin/blob/main/images/image-20220613194302486.png)

![image-20220613194320983](https://github.com/Conqcd/Rengin/blob/main/images/image-20220613194320983.png)

![image-20220613194334562](https://github.com/Conqcd/Rengin/blob/main/images/image-20220613194334562.png)

每帧渲染只一做一次直接光照+间接光照，但效果很差，噪声多，可以看到第一幅图的模样。第二幅图是做了降噪，用A-Trous Wavelet来进行采样。第三幅图是基于上一帧的结果来累计结果，可以看到跟离线的光线追踪很接近了。

最后还做了个小优化，基于morton code 的bvh 优化，从1fps到16fps,以上是在1070显卡上的结果，2060结果是4fps和30fps

![image-20220615201747174](https://github.com/Conqcd/Rengin/blob/main/images/image-20220615201747174.png)

![image-20220615201737592](https://github.com/Conqcd/Rengin/blob/main/images/image-20220615201737592.png)