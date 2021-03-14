import React, {ChangeEvent} from "react";

interface ReservationState {
    [k: string]: any
}

class Reservation extends React.Component<any, ReservationState> {
    constructor(props: any) {
        super(props);
        this.state = {
            isGoing: true,
            numberOfGuests: 2
        };

        this.handleInputChange = this.handleInputChange.bind(this);
    }

    handleInputChange(event: ChangeEvent<HTMLInputElement>) {
        const target = event.target;
        const value = target.type === 'checkbox' ? target.checked : target.value;
        const name = target.name;

        this.setState({
            [name]: value
        });
    }

    render() {
        return (
            <div>
                <form>
                    <label>
                        参与:
                        <input
                            name="isGoing"
                            type="checkbox"
                            checked={this.state.isGoing}
                            onChange={this.handleInputChange}/>
                    </label>
                    <br/>
                    <label>
                        来宾人数:
                        <input
                            name="numberOfGuests"
                            type="number"
                            value={this.state.numberOfGuests}
                            onChange={this.handleInputChange}/>
                    </label>
                </form>
                <p>{this.state.isGoing.toString()}</p>
                <p>{this.state.numberOfGuests.toString()}</p>
            </div>
        );
    }
}

export default Reservation
