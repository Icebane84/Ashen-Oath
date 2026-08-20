// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenGarrettShadowStepFlankAdapterComponent.generated.h"

/**
 * UAshenGarrettShadowStepFlankAdapterComponent
 * Companion component executing Garrett's shadow-step stealth flank repositioning.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenGarrettShadowStepFlankAdapterComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenGarrettShadowStepFlankAdapterComponent();

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Companion")
	float ShadowStepDistance = 500.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Companion")
	bool ExecuteShadowStepFlank(AActor* TargetEnemy);
};
