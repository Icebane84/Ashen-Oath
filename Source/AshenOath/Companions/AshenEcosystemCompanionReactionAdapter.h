// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenEcosystemCompanionReactionAdapter.generated.h"

/**
 * UAshenEcosystemCompanionReactionAdapter
 * Modulates companion somatic expressions (Serafina furrowed brow during high severity impact, Garrett alert stance during low consistency).
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenEcosystemCompanionReactionAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenEcosystemCompanionReactionAdapter();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Companions")
	void ApplySomaticBodyLanguage(FName CompanionID, float SeverityImpact);
};
