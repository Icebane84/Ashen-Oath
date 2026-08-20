// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Soul/AshenSoulStateVector.h"
#include "AshenNPCSocialFrictionPhenotypeAdapter.generated.h"

/**
 * UAshenNPCSocialFrictionPhenotypeAdapter
 * Modulates NPC interaction distance and reaction animations based on Corruption.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenNPCSocialFrictionPhenotypeAdapter : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenNPCSocialFrictionPhenotypeAdapter();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|NPC")
	void OnSoulStateInvalidated(const FSoulStateVector& NewState);

	UFUNCTION(BlueprintCallable, Category = "AshenOath|NPC")
	float GetSocialFrictionScalar() const { return SocialFrictionScalar; }

private:
	UPROPERTY(VisibleAnywhere, Category = "AshenOath|NPC")
	float SocialFrictionScalar = 0.0f;
};
