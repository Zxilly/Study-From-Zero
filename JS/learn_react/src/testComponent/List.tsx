import React from 'react'

class List extends React.Component<any, any> {
    render() {
        const a = [0, 1, 2, 3, 4, 5]
        const listItems = a.map((e) =>
            <li key={e.toString()}
            >{e}</li>
        )
        return <ol>{listItems}</ol>;
    }
}

export default List
