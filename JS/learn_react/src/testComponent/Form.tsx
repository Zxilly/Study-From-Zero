import React from "react";

interface FormProp{

}

interface FormState {
    value: string
}

class NameForm extends React.Component<FormProp,FormState> {
    constructor(props:FormProp) {
        super(props);
        this.state = {value: ''};

        this.handleChange = this.handleChange.bind(this);
        this.handleSubmit = this.handleSubmit.bind(this);
    }

    handleChange(event:React.ChangeEvent<HTMLInputElement>) {
        this.setState({value: event.target.value});
    }

    handleSubmit(event:React.FormEvent<HTMLFormElement>) {
        alert('提交的名字: ' + this.state.value);
        event.preventDefault();
    }

    render() {
        return (
            <form onSubmit={this.handleSubmit}>
                <label>
                    名字:
                    <input type="text" value={this.state.value} onChange={this.handleChange} />
                </label>
                <input type="submit" value="提交" />
            </form>
        );
    }
}

export default NameForm
