// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenSomaticIdentityResonanceComponent.generated.h"

/**
 * UAshenSomaticIdentityResonanceComponent
 * Actor Component scaling character somatic identity posture resilience and psychological resonance resistance.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenSomaticIdentityResonanceComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenSomaticIdentityResonanceComponent();

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Somatic Identity")
	float IdentityResonanceScalar = 1.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Somatic Identity")
	void UpdateIdentityResonance(float DeltaResonance);
};
