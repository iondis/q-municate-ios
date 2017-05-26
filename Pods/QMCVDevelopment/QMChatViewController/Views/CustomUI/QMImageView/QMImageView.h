//
//  QMImageView.h
//  QMChatViewController
//
//  Created by Andrey Ivanov on 27.06.14.
//  Copyright (c) 2014 Quickblox. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <SDWebImage/SDWebImageManager.h>
IB_DESIGNABLE
@protocol QMImageViewDelegate ;

typedef NS_ENUM(NSUInteger, QMImageViewType) {
    QMImageViewTypeNone,
    QMImageViewTypeCircle,
    QMImageViewTypeSquare
};

@interface QMImageView : UIImageView
/**
 Default QMUserImageViewType QMUserImageViewTypeNone
 */
@property (assign, nonatomic) QMImageViewType imageViewType;

@property (nonatomic) IBInspectable CGFloat borderWidth;
@property (strong, nonatomic, readonly) NSURL *url;

@property (weak, nonatomic) id <QMImageViewDelegate> delegate;

- (void)setImage:(UIImage *)image withKey:(NSString *)key;
- (void)setImageWithURL:(NSURL *)url;
- (void)setImageWithURL:(NSURL *)url
            placeholder:(UIImage *)placehoder
                options:(SDWebImageOptions)options
               progress:(SDWebImageDownloaderProgressBlock)progress
         completedBlock:(SDWebImageCompletionBlock)completedBlock;

- (void)setImageWithURL:(NSURL *)url
                  title:(NSString *)title
         completedBlock:(SDWebImageCompletionBlock)completedBlock;

- (UIImage *)originalImage;

@end

@protocol QMImageViewDelegate <NSObject>

- (void)imageViewDidTap:(QMImageView *)imageView;

@end