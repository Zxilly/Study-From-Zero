const operatorRe = /^[+\-*/]/;
const numberRe = /^\d+/;
const whiteRe = /^\s+/;

let input = "11+  245 - 34*623+55";

export enum Type {
  Number = "Num",
  OP_Plus = "+",
  OP_Minus = "-",
  OP_Multiply = "*",
  OP_Division = "/",
}

class Token {
  type: Type;
  value?: any;

  constructor(type: Type, value: any) {
    this.type = type;
    this.value = value;
  }
}

const tokens: Token[] = [];

while (input.length > 0) {
  for (const re of [whiteRe, operatorRe, numberRe]) {
    const matched = re.exec(input);
    if (matched !== null) {
      let newToken: Token;
      switch (re) {
        case whiteRe:
          input = input.slice(matched[0].length);
          continue;
        case operatorRe:
          let value = matched[0];
          let type: Type;
          switch (value) {
            case "+":
              type = Type.OP_Plus;
              break;
            case "-":
              type = Type.OP_Minus;
              break;
            case "*":
              type = Type.OP_Multiply;
              break;
            case "/":
              type = Type.OP_Division;
              break;
            default:
              throw new Error("Unexpected Operator");
          }
          newToken = new Token(type, value);
          break;
        case numberRe:
          newToken = new Token(Type.Number, matched[0]);
          break;
        default:
          throw new Error("Impossible");
      }
      console.log(newToken);
      tokens.push(newToken);
      input = input.slice(matched[0].length);
    }
  }
}

let reBuild = "";
for (const token of tokens) {
  reBuild += token.value;
}
console.log(reBuild);
