function mergeSort(arr) {
    let len = arr.length

    if (len > 1) {
        let mid = Math.round(len / 2);
        let left = arr.slice(0, mid)
        let right = arr.slice(mid)

        mergeSort(left)
        mergeSort(right)

        let i = 0
        let j = 0
        let k = 0
        
        while (i < left.length && j < right.length) {
            if (left[i] < right[j])
                arr[k++] = left[i++]
            else
                arr[k++] = right[j++]
        }
        while (i < left.length) 
            arr[k++] = left[i++]
        while (j < right.lenght)
            arr[k++] = right[j++]
    }
}

function main() {
    let arr = process.argv.slice(2)
    arr = arr.map(num => parseInt(num))
    arr = arr.filter(num => Number.isInteger(num))
    mergeSort(arr)
    console.log(arr)
}

if (require.main.children.length === 0)
    main()

