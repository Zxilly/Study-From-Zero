import React from 'react';
// import Clock from './testComponent/Clock'
import Logon from './testComponent/Logon'
import './App.css';
import FClike from "./testComponent/FClike";
import ReturnNull from "./testComponent/ReturnNull"


function App() {
    return (
        <div className="App">
            {/*<Clock name='This is a name'/>*/}
            <FClike/>
            <Logon isLoggedIn={true}/>
            <ReturnNull exist={true}/>
        </div>
    );
}

export default App;
