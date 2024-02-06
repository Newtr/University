const { send } = require('./m06_TRA');

try 
{
    const email = 'newt3rr@gmail.com';
    const password = 'skdu swlk wuby akea';
    const message = 'Hello from m06_TRA module!';

    send(email, password, message);

    console.log('Email sent successfully');
} 
catch (error) 
{
    console.error('Error sending email:', error);
}