import { Type } from "../exprTransformer/main";

class Tree {
  constructor(childNodes: (Tree | Leaf)[]) {
    this.childNodes = childNodes;
  }

  public childNodes: (Tree | Leaf)[];
}

class Leaf {
  public type: Type;
  public value: any;
  public attribute: any;

  constructor(type: Type, value: any, atrribute: any) {
    this.type = type;
    this.value = value;
    this.attribute = atrribute;
  }
}
