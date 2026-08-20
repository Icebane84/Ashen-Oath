// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "UI/AshenUserWidget_EmpathicNovaHUD.h"

void UAshenUserWidget_EmpathicNovaHUD::UpdateNovaHUDTelemetry(float InTrust, float InDebt, float InBurnout, float InCorruption)
{
	DisplayedMutualTrust = FMath::Clamp(InTrust, 0.0f, 1.0f);
	DisplayedIntegrationDebt = FMath::Clamp(InDebt, 0.0f, 1.0f);
	DisplayedSerafinaBurnout = FMath::Clamp(InBurnout, 0.0f, 1.0f);

	if (MPC_SomaticHUD && GetWorld())
	{
		UKismetMaterialLibrary::SetScalarParameterValue(GetWorld(), MPC_SomaticHUD, FName(TEXT("Corruption")), InCorruption);
		UKismetMaterialLibrary::SetScalarParameterValue(GetWorld(), MPC_SomaticHUD, FName(TEXT("Resolve")), DisplayedMutualTrust);
		UKismetMaterialLibrary::SetScalarParameterValue(GetWorld(), MPC_SomaticHUD, FName(TEXT("IntegrationDebt")), DisplayedIntegrationDebt);
		UKismetMaterialLibrary::SetScalarParameterValue(GetWorld(), MPC_SomaticHUD, FName(TEXT("Burnout")), DisplayedSerafinaBurnout);
	}

	if (DisplayedIntegrationDebt >= 0.75f)
	{
		ApplyDiegeticHUDNoise(DisplayedIntegrationDebt);
	}
}

void UAshenUserWidget_EmpathicNovaHUD::ApplyDiegeticHUDNoise(float IntegrationDebt)
{
	UE_LOG(LogTemp, Warning, TEXT("UAshenUserWidget_EmpathicNovaHUD: Applied Diegetic HUD Noise jitter (Debt: %.2f >= 0.75)!"),
		IntegrationDebt);
}
