const profile = <T extends {}>(obj: T) => {
  let RollNo = Math.floor(Math.random() * 100);
  return {
    ...obj,
    RollNo,
  };
};

let obj = profile({
  name: "John",
});

console.log(obj.name);

interface Resources<T> {
  name: string;
  RollNo: number;
  data: T;
}

const profile2: Resources<object> = {
  name: "John",
  RollNo: 1,
  data: { name: "John" },
};

const profile3: Resources<string[]> = {
  name: "John",
  RollNo: 1,
  data: ["John", "Doe"],
};
