// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "OverHeadWidget.generated.h"

/**
 * 
 */
UCLASS()
class NETWORKSTUDY_API UOverHeadWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void SetDisplayText(FString Text);

	UFUNCTION(BlueprintCallable)
	void ShowPlayerNetRole(APawn* Pawn);

public:
	UPROPERTY(meta=(BindWidget))
	class UTextBlock* DisplayText;
};
