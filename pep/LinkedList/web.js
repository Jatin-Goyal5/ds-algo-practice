// Web.js;
function fun() {
  let name = document.querySelector('table td input[name="username"]');
  let email = document.querySelector('table td input[name="email"]');
  let budget = document.querySelector('table td input[name="Budget"]');
  let projectDescription = document.querySelector(
    'table td input[name="Project Description"]'
  );
  let data =
    "Name: " +
    name.value +
    " \r\n" +
    "Email: " +
    email.value +
    " \r\n" +
    "Budget: " +
    budget.value +
    " \r\n" +
    "Project Description: " +
    projectDescription.value;
  const textToBLOB = new Blob([data], { type: "text/plain" });
  const sFileName = "formData.txt";
  let newLink = document.createElement("a");
  newLink.download = sFileName;
  if (window.webkitURL != null) {
    newLink.href = window.webkitURL.createObjectURL(textToBLOB);
  } else {
    newLink.href = window.URL.createObjectURL(textToBLOB);
    newLink.style.display = "none";
    document.body.appendChild(newLink);
  }
  newLink.click();
}
