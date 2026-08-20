// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Soul/AshenSoulStateVector.h"
#include "AshenSomaticPhenotypeIntegratorComponent.generated.h"

/**
 * UAshenSomaticPhenotypeIntegratorComponent
 * Connects breathing rate and eye shader controller components to FSoulStateVector invalidation pulses.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenSomaticPhenotypeIntegratorComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenSomaticPhenotypeIntegratorComponent();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Somatic")
	void OnSoulStateInvalidated(const FSoulStateVector& NewState);

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Somatic")
	float GetEyeEmissiveScalar() const { return EyeEmissiveScalar; }

private:
	UPROPERTY(VisibleAnywhere, Category = "AshenOath|Somatic")
	float EyeEmissiveScalar = 0.0f;
};
