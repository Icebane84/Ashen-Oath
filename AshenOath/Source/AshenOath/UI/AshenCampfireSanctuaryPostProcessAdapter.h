// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenCampfireSanctuaryPostProcessAdapter.generated.h"

/**
 * UAshenCampfireSanctuaryPostProcessAdapter
 * Warm amber hearth glow and soft peripheral bloom within campfire radius.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenCampfireSanctuaryPostProcessAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenCampfireSanctuaryPostProcessAdapter();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Visuals")
	void ApplyCampfireSanctuaryPostProcess(bool bInSanctuary, float WarmthIntensity);
};
