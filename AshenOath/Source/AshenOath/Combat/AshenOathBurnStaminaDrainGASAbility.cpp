// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Combat/AshenOathBurnStaminaDrainGASAbility.h"
#include "Combat/AshenCombatCharacter.h"
#include "Core/AshenOath_OathRegistryComponent.h"
#include "AshenOath_StaminaComponent.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "Components/SkeletalMeshComponent.h"

UAshenOathBurnStaminaDrainGASAbility::UAshenOathBurnStaminaDrainGASAbility()
{
}

bool UAshenOathBurnStaminaDrainGASAbility::ActivateOathBurnDebuffState()
{
	AActor* Avatar = GetAvatarActorFromActorInfo();
	if (!Avatar)
	{
		Avatar = Cast<AActor>(GetOuter());
	}
	if (!Avatar)
	{
		return false;
	}

	AAshenCombatCharacter* CombatChar = Cast<AAshenCombatCharacter>(Avatar);
	if (CombatChar)
	{
		if (UAshenOath_OathRegistryComponent* OathReg = CombatChar->FindComponentByClass<UAshenOath_OathRegistryComponent>())
		{
			if (OathReg->IsOathBurnActive())
			{
				// Drain stamina
				if (UAshenOath_StaminaComponent* Stamina = CombatChar->FindComponentByClass<UAshenOath_StaminaComponent>())
				{
					Stamina->ConsumeStamina(15.0f);
				}

				// Apply glowing visual crack parameters to dynamic materials
				if (USkeletalMeshComponent* MeshComp = CombatChar->GetMesh())
				{
					const int32 NumMats = MeshComp->GetNumMaterials();
					for (int32 i = 0; i < NumMats; ++i)
					{
						if (UMaterialInstanceDynamic* MID = Cast<UMaterialInstanceDynamic>(MeshComp->GetMaterial(i)))
						{
							MID->SetScalarParameterValue(TEXT("OathBurnActive"), 1.0f);
							MID->SetScalarParameterValue(TEXT("OathBurdenAmount"), OathReg->GetOathBurden());
						}
					}
				}

				UE_LOG(LogTemp, Warning, TEXT("UAshenOathBurnStaminaDrainGASAbility: Applied Oath Burn debuff (Burden: %.2f)!"),
					OathReg->GetOathBurden());
				return true;
			}
		}
	}

	return false;
}
