function theta = LMS(X, Y)
    m = size(X, 2);
    n = size(X, 1);
    X = [ones(n,1),X];
    max = 0;
    m = size(X, 2);
    theta = zeros(1,m);
    alpha = 0.01;
    for i = 1:n
        hx = X(i,:) * (theta');
        if(abs(hx - Y(i,1)) < 0.001 ) 
            return;
        end
        aJ = (hx - Y(i,1)) * X(i,:);
        theta = theta - alpha * aJ;
    end
return