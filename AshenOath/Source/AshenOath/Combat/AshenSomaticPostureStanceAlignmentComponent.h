// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenSomaticPostureStanceAlignmentComponent.generated.h"

/**
 * UAshenSomaticPostureStanceAlignmentComponent
 * Actor Component scaling character stance balance, posture resilience, and parry frame window alignment.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenSomaticPostureStanceAlignmentComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenSomaticPostureStanceAlignmentComponent();

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Somatic Posture")
	float PostureAlignmentScalar = 1.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Somatic Posture")
	void UpdatePostureAlignment(float DeltaAlignment);
};
