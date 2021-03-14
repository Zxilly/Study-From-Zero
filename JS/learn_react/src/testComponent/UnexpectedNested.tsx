function FancyBorder(props: any) {
    return (
        <div className={'FancyBorder FancyBorder-' + props.color} style={{fontSize: 'large'}}>
            {props.children}
        </div>
    );
}

function WelcomeDialog() {
    return (
        <FancyBorder color="blue">
            <h1 className="Dialog-title">
                Welcome
            </h1>
            <p className="Dialog-message">
                Thank you for visiting our spacecraft!
            </p>
        </FancyBorder>
    );
}

export default WelcomeDialog
