// Lấy thông tin testcases
const selectEl = document.getElementById("id_cases-0-input_file");

const inputTestcases = [...selectEl.options]
    .filter((option) => option.value.indexOf(".a") === -1)
    .map((option) => option.value);

// Nút thêm testcase mới
const addNewCaseEl = document.getElementById("add-case-row");

for (let iTest = 0; iTest < inputTestcases.length; ++iTest) {
    if (!document.getElementById(`id_cases-${iTest}-input_file`)) {
        addNewCaseEl.click();
    }

    const inputFileEl = document.getElementById(`id_cases-${iTest}-input_file`);
    const outputFileEl = document.getElementById(
        `id_cases-${iTest}-output_file`
    );
    const pointEl = document.getElementById(`id_cases-${iTest}-points`);

    let iTestStr = inputTestcases[iTest];
    const optionInput = Array.from(inputFileEl.options).find(
        (option) => option.value === iTestStr
    );
    const optionoutput = Array.from(outputFileEl.options).find(
        (option) => option.value === iTestStr + ".a"
    );

    optionInput.selected = true;
    optionoutput.selected = true;
    pointEl.value = 1;
}

const submitButtonEl = document.querySelector("input.btn.btn-primary");
submitButtonEl.click();
