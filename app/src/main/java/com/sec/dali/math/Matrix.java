package com.sec.dali.math;

// TODO
public class Matrix {
/**
     * @brief Constructor.
     *
     * Zero initializes the matrix.
     * @SINCE_1_0.0
     */
    public Matrix() {}

    /**
     * @brief Constructor.
     *
     * The matrix is initialized with the contents of 'array' which must contain 16 floats.
     * The order of the values for a transform matrix is:
     *
     * @code
     * [ xAxis.x, xAxis.y, xAxis.z, 0.0f, yAxis.x, yAxis.y, yAxis.z, 0.0f, zAxis.x, zAxis.y, zAxis.z, 0.0f, trans.x, trans.y, trans.z, 1.0f ]
     * @endcode
     *
     * @SINCE_1_0.0
     * @paramatrix[in] array Pointer of 16 floats data
     */
    public Matrix(final float[] array) { System.arraycopy(array, 0, matrix,0, array.length); }

    /**
     * @brief Constructs a matrix from quaternion.
     *
     * @SINCE_1_0.0
     * @param rotation Rotation as quaternion
     */
    public Matrix(final Quaternion rotation ) {
        final float xx = rotation.vector.x * rotation.vector.x;
        final float yy = rotation.vector.y * rotation.vector.y;
        final float zz = rotation.vector.z * rotation.vector.z;
        final float xy = rotation.vector.x * rotation.vector.y;
        final float xz = rotation.vector.x * rotation.vector.z;
        final float wx = rotation.vector.w * rotation.vector.x;
        final float wy = rotation.vector.w * rotation.vector.y;
        final float wz = rotation.vector.w * rotation.vector.z;
        final float yz = rotation.vector.y * rotation.vector.z;

        matrix[0] = 1.0f - 2.0f * (yy + zz);
        matrix[1] =        2.0f * (xy + wz);
        matrix[2] =        2.0f * (xz - wy);
        matrix[3] = 0.0f;

        matrix[4] =        2.0f * (xy - wz);
        matrix[5] = 1.0f - 2.0f * (xx + zz);
        matrix[6] =        2.0f * (yz + wx);
        matrix[7] = 0.0f;

        matrix[8] =        2.0f * (xz + wy);
        matrix[9] =        2.0f * (yz - wx);
        matrix[10]= 1.0f - 2.0f * (xx + yy);
        matrix[11]= 0.0f;

        matrix[12]= 0.0f;
        matrix[13]= 0.0f;
        matrix[14]= 0.0f;
        matrix[15]= 1.0f;
    }

    /**
     * @brief Copy finalructor.
     *
     * @SINCE_1_0.0
     * @paramatrix[in] matrix A reference to the copied matrix
     */
    public Matrix( Matrix matrix ) { System.arraycopy(matrix.matrix, 0, this.matrix,0, this.matrix.length); }

    public float matrix[] = new float[16]; ///< The elements of the matrix
}
