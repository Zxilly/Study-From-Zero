
### `jsx/tsx` 文件中的回调函数会丢失 `this`

解决方案：

> 如果你正在使用实验性的 public class fields 语法，你可以使用 class fields 正确的绑定回调函数：[1]

1. 使用 `function = ()=>{}`

2. 在构造函数中 `this.function = this.function.bind(this)`

3. 在回调函数中使用箭头函数
