// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Soul/AshenSoulStateVector.h"
#include "AshenGASEffectStanceBlendAdapterComponent.generated.h"

/**
 * UAshenGASEffectStanceBlendAdapterComponent
 * Binds active GameplayEffects to posture blend tree weights.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenGASEffectStanceBlendAdapterComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenGASEffectStanceBlendAdapterComponent();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Combat")
	void OnSoulStateInvalidated(const FSoulStateVector& NewState);

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Combat")
	float GetStanceAggressionWeight() const { return StanceAggressionWeight; }

private:
	UPROPERTY(VisibleAnywhere, Category = "AshenOath|Combat")
	float StanceAggressionWeight = 0.5f;
};
