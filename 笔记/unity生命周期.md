![生命周期](/unity生命周期.jpg)

生命周期中的所有方法都是Unity 系统自己回调的，不需要手动调用。

Awake() 用于初始化并且永远只会执行一次   
OnEnable() 在脚本每次被激活时都执行一次   
Start() 在初始化的下一帧执行，并且永远只会执行一次   
FixedUpdate() 固定更新。默认情况下每0.02秒调用一次，可以在ProjectSetting中更改   
Update() 每一帧执行时调用此方法
LateUpdate() Update()方法执行后调用该方法
OnDisable() 每次脚本禁用时执行一次
OnApplicationQuit() 应用退出时执行一次
OnDestroy() 用于脚本销毁并且永远只会执行一次

