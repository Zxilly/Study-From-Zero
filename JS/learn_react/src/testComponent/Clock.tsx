import React, {SyntheticEvent} from "react";

interface State {
    date: number
}

interface Prop {
    name: string
}

class Clock extends React.Component<Prop, State> {
    private timerID: NodeJS.Timeout | undefined;

    constructor(props: Prop) {
        super(props);
        this.state = {date: Math.random()};

        // this.handleClick = this.handleClick.bind(this)
    }

    componentDidMount() {
        this.timerID = setInterval(
            () => this.tick(),
            100 * Math.random()
        );
    }

    componentWillUnmount() {
        this.stopRefresh()
    }

    tick() {
        this.setState({
            date: Math.random()
        });
    }

    handleClick = (e: SyntheticEvent) => {
        e.preventDefault()
        console.log(this)
        this.stopRefresh()
    }

    stopRefresh() {
        clearInterval(this.timerID!);
    }

    render() {
        return (
            <div>
                <h1>Hello, world!</h1>
                <h1>Prop is {this.props.name}</h1>
                <h2
                    onClick={this.handleClick}
                >It is {this.state.date}.</h2>
            </div>
        );
    }
}

export default Clock
