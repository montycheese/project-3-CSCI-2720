setwd("C:/Users/4malteses/Desktop/plot")

# set up data size vector
data.size <- vector()
for (i in 1:100) {
  data.size[i] <- i * 100
}

# load cmp number
data.cmp <- read.table("Insert.txt", header = FALSE, sep = " ", stringsAsFactors=F)
data.cmp <- as.character(data.cmp)
data.cmp <- data.cmp[1:100]

plot(data.size, 
     data.cmp,
     type = "l",
     xlab= "Data Size",
     ylab="Numbers of Comparisons",
     main = "Insertion Sorting")
lines(data.size, 
      0.26*data.size*data.size, 
      type ="l", 
      col = "Red")
lines(data.size, data.size, type ="l", col = "Green")
