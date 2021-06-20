function computeArea(
    A: number,
    B: number,
    C: number,
    D: number,
    E: number,
    F: number,
    G: number,
    H: number
): number {
    let width = Math.min(C, G) - Math.max(A, E);
    let height = Math.min(H, D) - Math.max(B, F);
    let commonArea = Math.max(width, 0) * Math.max(height, 0);
    let AreaSum = (C - A) * (D - B) + (G - E) * (H - F);
    return AreaSum - commonArea;
}

console.log(computeArea(-3, 0, 3, 4, 0, -1, 9, 2));
