import React, {MouseEventHandler} from "react";

interface LogProp {
    onClick: MouseEventHandler
}


function LoginButton(props: LogProp): JSX.Element {
    return (
        <button onClick={props.onClick}>
            Login
        </button>
    );
}

function LogoutButton(props: LogProp) {
    return (
        <button onClick={props.onClick}>
            Logout
        </button>
    );
}

interface LoginCtrProp {
    isLoggedIn:Boolean
}

interface LoginCtrState {
    isLoggedIn:Boolean
}

class LoginControl extends React.Component <LoginCtrProp,LoginCtrState>{
    constructor(props:LoginCtrProp) {
        super(props);
        // this.handleLoginClick = this.handleLoginClick.bind(this);
        // this.handleLogoutClick = this.handleLogoutClick.bind(this);
        this.state = {isLoggedIn: this.props.isLoggedIn};
    }

    handleLoginClick = () => {
        this.setState({isLoggedIn: true});
    }

    handleLogoutClick = () => {
        this.setState({isLoggedIn: false});
    }

    render() {
        const isLoggedIn = this.state.isLoggedIn;
        let button;
        if (isLoggedIn) {
            button = <LogoutButton onClick={this.handleLogoutClick}/>;
        } else {
            button = <LoginButton onClick={this.handleLoginClick}/>;
        }

        return (
            <div>
                <p>Login Status {isLoggedIn.toString()}</p>
                {button}
            </div>
        );
    }
}

export default LoginControl
