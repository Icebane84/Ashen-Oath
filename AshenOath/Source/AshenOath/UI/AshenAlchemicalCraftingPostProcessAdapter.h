// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenAlchemicalCraftingPostProcessAdapter.generated.h"

/**
 * UAshenAlchemicalCraftingPostProcessAdapter
 * Manages campfire crafting visual mood: warm amber firelight bloom, shallow depth-of-field journal focus, and clockwork brass specular highlights.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenAlchemicalCraftingPostProcessAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenAlchemicalCraftingPostProcessAdapter();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Visuals")
	void ApplyCampfireCraftingPostProcess(bool bIsWorkstationOpen, float CampfireIntensity);
};
