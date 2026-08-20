// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AshenOathResolutionHeartstoneLocus.generated.h"

/**
 * AAshenOathResolutionHeartstoneLocus
 * World actor processing non-skippable Oath Resolution rituals at Heartstone campfires when OathBurden >= 1.0f.
 */
UCLASS()
class ASHENOATH_API AAshenOathResolutionHeartstoneLocus : public AActor
{
	GENERATED_BODY()
public:
	AAshenOathResolutionHeartstoneLocus();
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | World")
	bool bResolutionPending = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | World")
	bool ExecuteNonSkippableOathResolution();
};
