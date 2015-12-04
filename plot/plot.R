setwd("C:/Users/4malteses/Desktop/plot")

### Insertion Sorting
# set up data size vector
data.size <- vector()
for (i in 1:100) {
  data.size[i] <- i * 1000
}

# load cmp number
data.cmp <- read.table("Insert.txt", header = FALSE, sep = " ", stringsAsFactors=F)
data.cmp <- as.character(data.cmp)
data.cmp <- data.cmp[1:100]

plot(data.size, 
     data.cmp,
     type = "l",
     bty="n",
     xlab= "Data Size",
     ylab="Numbers of Comparisons",
     main = "Insertion Sorting")
lines(data.size, 
      0.26*data.size*data.size, 
      type ="l", 
      col = "red")
# legend
legend("topleft", 
       bty="n",
       legend = c("Y = 0.26*X*X"),
       lty = c(1), 
       col = c("red"),
       lwd = 1,
       pt.lwd = 1,
       text.width = 1)


### Merge Sorting
# set up data size vector
data.size <- vector()
for (i in 1:100) {
  data.size[i] <- i * 1000
}

# load cmp number
data.cmp <- read.table("Merge.txt", header = FALSE, sep = " ", stringsAsFactors=F)
data.cmp <- as.character(data.cmp)
data.cmp <- data.cmp[1:100]

plot(data.size, 
     data.cmp,
     type = "l",
     bty="n",
     xlab= "Data Size",
     ylab="Numbers of Comparisons",
     main = "Merge Sorting")
lines(data.size, 
      1.5*data.size*log(data.size), 
      type ="l", 
      col = "red")
# legend
legend("topleft", 
       bty="n",
       legend = c("Y = 1.5*X*log(X)"),
       lty = c(1), 
       col = c("red"),
       lwd = 1,
       pt.lwd = 1,
       text.width = 1)


### Quick Sorting
# set up data size vector
data.size <- vector()
for (i in 1:100) {
  data.size[i] <- i * 1000
}

# load cmp number
data.cmp <- read.table("Quick.txt", header = FALSE, sep = " ", stringsAsFactors=F)
data.cmp <- as.character(data.cmp)
data.cmp <- data.cmp[1:100]

plot(data.size, 
     data.cmp,
     type = "l",
     bty="n",
     xlab= "Data Size",
     ylab="Numbers of Comparisons",
     main = "Quick Sorting")
lines(data.size, 
      1.8*data.size*log(data.size), 
      type ="l", 
      col = "red")
# legend
legend("topleft", 
       bty="n",
       legend = c("Y = 1.8*X*log(X)"),
       lty = c(1), 
       col = c("red"),
       lwd = 1,
       pt.lwd = 1,
       text.width = 1)