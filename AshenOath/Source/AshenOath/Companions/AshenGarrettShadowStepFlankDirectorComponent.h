// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenGarrettShadowStepFlankDirectorComponent.generated.h"

/**
 * UAshenGarrettShadowStepFlankDirectorComponent
 * Companion component directing Garrett's shadow-step tactical flank positioning.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenGarrettShadowStepFlankDirectorComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenGarrettShadowStepFlankDirectorComponent();

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Companion")
	float ShadowStepFlankRadius = 500.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Companion")
	bool DirectShadowStepFlank(AActor* TargetEnemy);
};
