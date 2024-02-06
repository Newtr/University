function thirdJob(data) {
    return new Promise((resolve, reject) =>{
        if(typeof data !== 'number'){
            reject("data is not a number");
        }
        else{
            data % 2 == 1 ? setTimeout(() => resolve("odd"), 1000) :
                            setTimeout(() => reject("even"),2000)
        }
    });
}

thirdJob(2).then((result) =>{
    console.log("С использованием обработчиков Promise:", result);
}).catch((error) => {
    console.log("Ошибка c использованием обработчиков Promise:", error);
}); 

async function performThirdJob(data) {
    try {
      const result = await thirdJob(data);
      console.log("С использованием async/await: ", result);
    } catch (error) {
      console.error("Ошибка c использованием async/await:", error);
    }
}

performThirdJob(2);
