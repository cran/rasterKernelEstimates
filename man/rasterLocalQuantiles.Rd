% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/rasterLocalQuantiles.R
\name{rasterLocalQuantiles}
\alias{rasterLocalQuantiles}
\title{Local quantiles for an in memory raster image}
\usage{
rasterLocalQuantiles(r, W, q = 50)
}
\arguments{
\item{r}{An in memory raster image.}

\item{W}{A matrix of weights used to specify a local neighborhood.  The quantile 
 kernel will be applied to each pixel in \code{r}.  Dimensions must be non-zero 
and odd.}

\item{q}{A quantile.  This value is required to be in the inclusive interval from 
0 to 100.}
}
\value{
An in memory raster image of local quantiles.
}
\description{
\code{rasterLocalQuantiles} finds the quantile within the positive valued neighborhood 
of \code{W}.
}
\details{
A spatial neighborhood is calculated for each pixel in \code{r}.
  The spatial neighborhood for each pixel is defined by the weight matrix
  \code{W}, where the center of the odd dimensioned matrix \code{W} is identified 
  with the target pixel.  The target pixel value is replaced with the
  quantile of the neighborhood identified by \code{W}.  Only non-missing or neighbors
  with non-zero weights are used in the calculation.  Quantile calculation uses
  the inverse empirical CDF transform, equivalent to \code{stats::quantile} type=1.
}
\examples{
r <- raster::raster( matrix(rnorm(36),6,6)) 
W <- matrix(1,3,3)
medianR <- rasterLocalQuantiles(r,W)
}
