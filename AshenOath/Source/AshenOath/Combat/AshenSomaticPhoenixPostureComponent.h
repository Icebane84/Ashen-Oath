// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenSomaticPhoenixPostureComponent.generated.h"

/**
 * UAshenSomaticPhoenixPostureComponent
 * Somatic combat posture component aligning stance blend trees with the sovereign Phoenix ascension state.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenSomaticPhoenixPostureComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenSomaticPhoenixPostureComponent();

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Somatic Posture")
	float PhoenixStanceAlignmentScalar = 1.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Somatic Posture")
	void AlignPhoenixPostureStance();
};
