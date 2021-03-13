import React from 'react'

interface ReturnNullProp {
    exist?: Boolean
}

export default function ReturnNull(props:ReturnNullProp):JSX.Element | null{
    if (!props.exist) {
        return null
    }

    return <p>It did exist</p>
}
