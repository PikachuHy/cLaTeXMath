const helloDemo = `
Hello from $\\MicroTeX$, welcome 🥰! $\\MicroTeX$ is a fast, cross-platform and embeddable
$\\LaTeX$ (part of) rendering library.

It supports complex math formula layout and rendering, for example, the Fourier transform:
$F(\\omega)=\\int_{-\\infty}^{+\\infty}f(t)e^{-i\\omega_nt}dt$

And inline formula, for example, for quadratic equation: $ax^2+bx+c=0$, as we know:
$x=\\frac{-b\\pm\\sqrt{b^2-4ac}}{2a}$.

And inter-line formula, for example, the Maxwell equation:
$$\\text{Maxwell equations:}\\left\\{
\\begin{array}{ll}
  \\Nabla\\cdot\\mathbf{E}=0 & \\Nabla\\cdot\\mathbf{E}=-\\frac{\\partial\\mathbf{B}}{\\partial t},\\\\
  \\Nabla\\cdot\\mathbf{B}=0 & \\Nabla\\cdot\\mathbf{B}=\\mu_0\\varepsilon_0\\frac{\\partial\\mathbf{E}}{\\partial t}.
\\end{array}
\\right.$$

And fancy emojis:
$$F(x) = \\displaystyle\\int_🙂^😀f(x)dx\\\\
\\log_😄️😅️=💧️\\\\
\\displaystyle\\sum_{i=0}^\\infty💰️=🤣️\\\\
\\prod_{i=0}^\\infty i\\times💰️=😭️\\\\
%ZWJ
\\char"1f468+\\char"1f469+\\char"1f466=👨‍👩‍👦
$$

Finally: $$\\shadowbox{\\text{Have fun 🥰!}}$$
`

export {helloDemo};
