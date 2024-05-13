## Dynamic Programming State and Recurrence

### DP State
The state is represented by:
- `mask`: A bitmask indicating which elements have been used.
- `previous_id`: The index of the previously used element.

### Recurrence
The recurrence relation is defined as:
- `fun(mask, previous_id) -> fun(mask & (1 << id), id)`

This means that the function `fun` takes the current `mask` and `previous_id`, and updates them by including the element at index `id` in the mask and setting `id` as the new `previous_id`.
