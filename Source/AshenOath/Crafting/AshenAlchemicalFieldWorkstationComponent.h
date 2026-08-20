// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Crafting/AshenAlchemicalCraftingTypes.h"
#include "AshenAlchemicalFieldWorkstationComponent.generated.h"

/**
 * UAshenAlchemicalFieldWorkstationComponent
 * Actor Component managing Garrett's portable field workstation, clockwork dial selection, and recipe synthesis during campfire rest.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenAlchemicalFieldWorkstationComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenAlchemicalFieldWorkstationComponent();
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Crafting")
	EAlchemicalItemType SelectedRecipeItem = EAlchemicalItemType::GloomwoodTripwire;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Crafting")
	void SelectRecipeDial(EAlchemicalItemType InItem);

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Crafting")
	int32 GetCraftedItemCount(EAlchemicalItemType InItem) const;
};
