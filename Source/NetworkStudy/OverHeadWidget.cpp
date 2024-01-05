// Fill out your copyright notice in the Description page of Project Settings.


#include "OverHeadWidget.h"
#include "Components/TextBlock.h"

void UOverHeadWidget::SetDisplayText(FString Text)
{
	if (DisplayText)
		DisplayText->SetText(FText::FromString(Text));
}

void UOverHeadWidget::ShowPlayerNetRole(APawn* Pawn)
{
	ENetRole LocalRole = Pawn->GetLocalRole();
	
	FString LocalRoleStr;
	switch (LocalRole)
	{
		case ENetRole::ROLE_SimulatedProxy:
			LocalRoleStr = FString("SimulatedProxy");
			break;
		case ENetRole::ROLE_AutonomousProxy:
			LocalRoleStr = FString("AutonomousProxy");
			break;
		case ENetRole::ROLE_Authority:
			LocalRoleStr = FString("Authority");
			break;
	}

	ENetRole RemoteRole = Pawn->GetRemoteRole();
	
	FString RemoteRoleStr;
	switch (RemoteRole)
	{
	case ENetRole::ROLE_SimulatedProxy:
		RemoteRoleStr = FString("SimulatedProxy");
		break;
	case ENetRole::ROLE_AutonomousProxy:
		RemoteRoleStr = FString("AutonomousProxy");
		break;
	case ENetRole::ROLE_Authority:
		RemoteRoleStr = FString("Authority");
		break;
	}

	FString Result = FString::Printf(TEXT("Local : %s\n Remote: %s"), *LocalRoleStr, *RemoteRoleStr);
	SetDisplayText(Result);
}
