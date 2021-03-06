/*!
 * Copyright (C) tkornuta, IBM Corporation 2015-2019
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
/*!
 * \file WindowMatrix2D.hpp
 * \brief Window displaying 2d matrix (e.g. a grayscale image).
 * \author tkornut
 * \date Dec 22, 2015
 */

#ifndef SRC_VISUALIZATION_OPENGL_WINDOWMATRIX2D_HPP_
#define SRC_VISUALIZATION_OPENGL_WINDOWMATRIX2D_HPP_

#include <opengl/visualization/Window.hpp>

// Dependencies on core types.
#include <types/MatrixTypes.hpp>
using namespace mic::types;

namespace mic {
namespace opengl {
namespace visualization {

/*!
 * \brief OpenGL-based window responsible for displaying 2D matrices.
 * \author tkornuta/krocki
 */
class WindowMatrix2D: public Window {
public:
	/*!
	 * Constructor. NULLs the image pointer.
	 */
	WindowMatrix2D(std::string name_ = "Matrix2D",
			unsigned int position_x_ = 0, unsigned int position_y_ = 0,
			unsigned int width_ = 512, unsigned int height_ = 512);

	/*!
	 * Destructor.
	 */
	virtual ~WindowMatrix2D();


	/*!
	 * Refreshes the content of the window.
	 */
	void displayHandler(void);

	/*!
	 * Sets displayed matrix.
	 * @param displayed_matrix_
	 */
	void setMatrixSynchronized(mic::types::MatrixXf & displayed_matrix_);

	/*!
	 * Sets displayed matrix. Unsynchronized i.e. must be used inside of manually synchronized section.
	 * @param displayed_matrix_
	 */
	void setMatrixUnsynchronized(mic::types::MatrixXf & displayed_matrix_);


	/*!
	 * Sets pointer to displayed matrix.
	 * @param displayed_matrix_
	 */
	void setMatrixPointerSynchronized(mic::types::MatrixXfPtr displayed_matrix_ptr_);

	/*!
	 * Sets pointer to displayed matrix. Unsynchronized i.e. must be used inside of manually synchronized section.
	 * @param displayed_matrix_
	 */
	void setMatrixPointerUnsynchronized(mic::types::MatrixXfPtr displayed_matrix_ptr_);

private:

	/*!
	 * Pointer to displayed matrix.
	 */
	mic::types::MatrixXfPtr displayed_matrix_ptr;
};

} /* namespace visualization */
} /* namespace opengl */
} /* namespace mic */

#endif /* SRC_VISUALIZATION_OPENGL_WINDOWMATRIX2D_HPP_ */
