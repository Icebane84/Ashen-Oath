// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenSkeletalSightTracingAIDirectorComponent.generated.h"

/**
 * UAshenSkeletalSightTracingAIDirectorComponent
 * Implements skeletal sight tracing using GetActorEyesViewPoint on character head sockets to calculate posture-dependent field-of-view profiles.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenSkeletalSightTracingAIDirectorComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenSkeletalSightTracingAIDirectorComponent();
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, Category = "Ashen Oath | AI")
	FName HeadSocketName = FName(TEXT("head"));

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | AI")
	float CalculateEffectiveVisionConeAngle(bool bIsHunchedGuarded) const;
};
