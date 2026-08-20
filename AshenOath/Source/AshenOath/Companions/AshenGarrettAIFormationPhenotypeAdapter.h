// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Soul/AshenSoulStateVector.h"
#include "AshenGarrettAIFormationPhenotypeAdapter.generated.h"

/**
 * UAshenGarrettAIFormationPhenotypeAdapter
 * Connects Garrett StateTree AI formation distance to GarrettTrust and Isolation.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenGarrettAIFormationPhenotypeAdapter : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenGarrettAIFormationPhenotypeAdapter();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Companions")
	void OnSoulStateInvalidated(const FSoulStateVector& NewState);

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Companions")
	float GetFormationDistance() const { return FormationDistance; }

private:
	UPROPERTY(VisibleAnywhere, Category = "AshenOath|Companions")
	float FormationDistance = 300.0f;
};
