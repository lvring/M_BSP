# M_BSP
一款基于时间片实现的Cotex-M内核下的BSP，加速嵌入式软件开发

M_BSP是个人根据需求和在实际工程使用中对裸机代码的总结和整合。

src:
	1\CORE
	
	2\FLASH
	
	3\MEMORY
	
	4\PORT
	
	5\SUP\
	
	
1、CORE：主要实现基于简单时间片的轮询调度
2、FLASH：准备实现内部flash的KVDB功能
3、MEMORY：实现内部的内存管理，若使用IDE自动管理即可删去
4、PORT：主要于开发平台相关，基本接口和实现函数
5、SUP：一些第三方库的支持，目前实现了精简版printf的实现


# 使用说明
暂无

# 版本
2019/4/10  由于没有事干就写了一点代码
2019/4/15  上传至GITHUB，并对其中一些不完美的地方进行了修改（可能还有其它未知bug，求各路大神指导）

# 感谢
感谢sudashannon指出了我代码中的不足（师兄）
