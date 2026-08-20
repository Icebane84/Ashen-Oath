// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenGarrettShadowStepPincerDirectorComponent.generated.h"

/**
 * UAshenGarrettShadowStepPincerDirectorComponent
 * Companion component directing Garrett's shadow-step pincer tactical positioning.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenGarrettShadowStepPincerDirectorComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenGarrettShadowStepPincerDirectorComponent();

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Companion")
	float ShadowStepPincerRadius = 550.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Companion")
	bool DirectShadowStepPincerStrike(AActor* TargetEnemy);
};
